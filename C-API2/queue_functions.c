#include <stdio.h>
#include <Python.h>
#include <stdlib.h>

/**
Определение функций 
Очередь
Проверка на пустую очередь*/

int queue_empty(const char *str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
		i++;
	if(i == 0){
		return 0;
	} else {
		return 1;
	}
}

/* Число элементов очереди*/
int queue_size(const char *str)
{
	int i,k;
	i = 0;
	k = 0;
	while(str[i] != '\0'){
		if(str[i] == ','){
			k++;
		}
		i++;}
	if(i == 0){
		return 0;
	} else {
		return k+1;
	}
}

/*добавляет в пустой dest первый элемент*/
void queue_top(const char *str, char *dest)
{
	int i = 0;
	while(str[i] != ','){
		dest[i] = str[i];
		i++;
	};
	dest[i] = '\0';
}

/* Удаление первого элемента */
void queue_pop(char *str){
	int i = 0;
	int j = 0;
	char dest[20];
	while(str[i] != ','){
		i++;
	};
	i++;
	while(str[i] != '\0'){
		dest[j] = str[i];
		i++;
		j++;
	};
	dest[j] = '\0';
	i = 0;
	while(dest[i] != '\0'){
		str[i] = dest[i];
		i++;
	};
	str[i] = '\0';
}

/* добавить элемент в конец списка*/
void queue_push(char *str, const char *var){
	int i,j;
	for(i = 0; str[i]; i++)
		{}
	str[i] = ',';
	i++;
	for(j = 0; var[j]; j++)
	{
		str[i]  = var[j];
		i++;
	}
	str[i] = '\0';
}

/* Возвращает последний элеммент очереди*/
void queue_back(const char *str, char *dest){
	int k = queue_size(str) - 1;
	int i = 0;
	int j = 0;
	while(k>0){
		if(str[i] == ','){
			k--;
		}
		i++;
	}
	while(str[i] != '\0'){
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
}

/* Стек */ 


/**
Определение объектов Python
*/
static PyObject* c_queue_empty(PyObject* self, PyObject* args)
{
	char str;

	if (!PyArg_ParseTuple(args, "s", &str)) 
		return NULL;

	return Py_BuildValue("s", queue_empty(str));
}

static PyObject* c_queue_size(PyObject* self, PyObject* args)
{
	char str;

	if (!PyArg_ParseTuple(args, "s", &str)) 
		return NULL;

	return Py_BuildValue("s", queue_size(str));
}

static PyObject* c_queue_top(PyObject* self, PyObject* args)
{
	char str,dest;

	if (!PyArg_ParseTuple(args, "ss", &str, &dest)) 
		return NULL;

	/*return Py_BuildValue("s", queue_top(str,dest));*/
}

static PyObject* c_queue_pop(PyObject* self, PyObject* args)
{
	char str;

	if (!PyArg_ParseTuple(args, "s", &str)) 
		return NULL;

	/*return Py_BuildValue("s", queue_pop(str));*/
}

static PyObject* c_queue_push(PyObject* self, PyObject* args)
{
	char str,var;

	if (!PyArg_ParseTuple(args, "ss", &str, &var)) 
		return NULL;

	/*return Py_BuildValue("s", queue_push(str,var));*/
}

static PyObject* c_queue_back(PyObject* self, PyObject* args)
{
	char str,dest;

	if (!PyArg_ParseTuple(args, "ss", &str, &dest)) 
		return NULL;

	/*return Py_BuildValue("s", queue_back(str,dest));*/
}

static PyMethodDef qeueue_methods[] = {
	{"c_queue_empty", c_queue_empty, METH_VARARGS, "Проверка на пустую очередь"},
	{"c_queue_size",  c_queue_size,  METH_VARARGS, "Число элементов очереди"},
	{"c_queue_top",   c_queue_top,   METH_VARARGS, "добавляет в пустой dest первый элемент"},
	{"c_queue_pop",   c_queue_pop,   METH_VARARGS, "Удаление первого элемента"},
	{"c_queue_push",  c_queue_push,  METH_VARARGS, "добавить элемент в конец списка"},
	{"c_queue_back",  c_queue_back,  METH_VARARGS, "Возвращает последний элеммент очереди"},
	{NULL, NULL, 0, NULL}

};


PyMODINIT_FUNC initdistributions(void)
{
    Py_InitModule("queue", qeueue_methods);
}