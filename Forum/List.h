#pragma once
#include "user.h"
#include "Post.h"
using namespace std;
struct userList{
	user userData;
	struct userList *next;
}typedef userList;

struct postList{
	Post posts;
	struct postList *next;
}typedef postList;