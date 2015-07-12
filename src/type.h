/*
 * type.h
 *
 *  Created on: Jul 12, 2015
 *      Author: domagoj
 */

#ifndef SRC_TYPE_H_
#define SRC_TYPE_H_

enum line_type
{
	L_IF,
	L_ELSEIF,
	L_ELSE,
	L_ENDIF,
	L_OTHER
};

enum state_type
{
	S_EMPTY,
	S_IF,
	S_ELSEIF,
	S_ELSE
};

typedef enum line_type line_t;
typedef enum state_type state_t;


#endif /* SRC_TYPE_H_ */
