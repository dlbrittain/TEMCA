%module list

%module MCSControl
%{
	#include "MCSControl.h"
	#include "stdafx.h"
	#include "windows.h"
	#include <conio.h>
	#include <ctype.h>
%}

%include "MCSControl.h"
%include <windows.i>  