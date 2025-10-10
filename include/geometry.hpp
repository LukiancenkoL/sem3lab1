#pragma once

#include <cstring>
#include <cstddef>
#include "list.hpp"

class Shape {
public:
	virtual void move(float x, float y) = 0;
};

class Point : public Shape {
public:
	float get_x() {
		return this->m_x;
	}

	float get_y() {
		return this->m_y;
	}

	void set_x(float value) {
		this->m_x = value;
	}

	void set_y(float value) {
		this->m_y = value;
	}

	void move(float x, float y) {
		this->m_x += x;
		this->m_y += y;
	}

private:
	float m_x;
	float m_y;
};

class Line : public Shape {
public:
	const Point& get_p1() {
		return this->p1;
	}

	const Point& get_p2() {
		return this->p2;
	}

	void set_p1(const Point& value) {
		this->p1 = value;
	}

	void set_p2(const Point& value) {
		this->p2 = value;
	}

	void move(float x, float y) {
		p1.move(x, y);
		p2.move(x, y);
	}

private:
	Point p1;
	Point p2;
};

class Triangle : public Shape {
public:
	const Point& get_p1() {
		return this->p1;
	}

	const Point& get_p2() {
		return this->p2;
	}

	const Point& get_p3() {
		return this->p3;
	}

	void set_p1(const Point& value) {
		this->p1 = value;
	}

	void set_p2(const Point& value) {
		this->p2 = value;
	}

	void set_p3(const Point& value) {
		this->p3 = value;
	}

	void move(float x, float y) {
		p1.move(x, y);
		p2.move(x, y);
		p3.move(x, y);
	}

private:
	Point p1;
	Point p2;
	Point p3;
};

class Circle : public Shape {
public:
	const Point& get_center() {
		return this->center;
	}

	void set_center(Point value) {
		this->center = value;
	}

	float get_radius() {
		return this->radius;
	}

	void set_radius(float value) {
		this->radius = value;
	}

	void move(float x, float y) {
		center.move(x, y);
	}

private:
	Point center;
	float radius;
};

class Rectangle : public Shape {
public:
	const Point& get_p1() {
		return this->p1;
	}

	const Point& get_p2() {
		return this->p2;
	}

	const Point& get_p3() {
		return this->p3;
	}

	const Point& get_p4() {
		return this->p4;
	}

	void set_p1(const Point& value) {
		this->p1 = value;
	}

	void set_p2(const Point& value) {
		this->p2 = value;
	}

	void set_p3(const Point& value) {
		this->p3 = value;
	}

	void set_p4(const Point& value) {
		this->p4 = value;
	}

	void move(float x, float y) {
		p1.move(x, y);
		p2.move(x, y);
		p3.move(x, y);
		p4.move(x, y);
	}

private:
	Point p1;
	Point p2;
	Point p3;
	Point p4;
};

class Square : public Rectangle {};

class Polygon : public Shape {
	Polygon(List<Point>& v)
		: vertices(v) {
	}

	const List<Point>& get_vertices() {
		return this->vertices;
	}

	void set_vertices(const List<Point>& value) {
		this->vertices = value;
	}

	void move(float x, float y) {
		for (size_t i = 0; i < vertices.length(); i++){
			vertices.get_mut(i).move(x, y);
		}
	}

private:
	List<Point>& vertices;
};
