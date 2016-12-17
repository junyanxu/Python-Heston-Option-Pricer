//
//  Option.c
//  Option
//
//  Created by junyan on 10/21/16.
//  Copyright © 2016 junyan. All rights reserved.
//

#include "BSLib.hpp"
#include "BSDoc.hpp"
#include <Python.h>

static PyObject *SpamError;

static PyObject * Option_BSCall(PyObject *self, PyObject *args)
{
    double S, K, T, Sigma, d, r;
    if (!PyArg_ParseTuple(args, "dddddd", &S, &K, &T, &Sigma, &d, &r)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(BSCall(S, K, T, Sigma, d, r));
}

static PyObject * Option_BSPut(PyObject *self, PyObject *args)
{
    double S, K, T, Sigma, d, r;
    if (!PyArg_ParseTuple(args, "dddddd", &S, &K, &T, &Sigma, &d, &r)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(BSPut(S, K, T, Sigma, d, r));
}

static PyObject * Option_BSVega(PyObject *self, PyObject *args)
{
    double  S, K, T, Sigma, d, r;
    if (!PyArg_ParseTuple(args, "dddddd", &S, &K, &T, &Sigma, &d, &r)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(BSVega(S, K, T, Sigma, d, r));
}

static PyObject * Option_BSCallIV(PyObject *self, PyObject *args)
{
    double C, S, K, T, d, r;
    if (!PyArg_ParseTuple(args, "dddddd", &C, &S, &K, &T, &d, &r)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(BSCallIV(C, S, K, T, d, r));
}

static PyObject * Option_BSPutIV(PyObject *self, PyObject *args)
{
    double P, S, K, T, d, r;
    if (!PyArg_ParseTuple(args, "dddddd", &P, &S, &K, &T, &d, &r)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(BSPutIV(P, S, K, T, d, r));
}

static PyObject * Option_HestonCall(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, StepSize;
    if (!PyArg_ParseTuple(args, "dddddddddd", &S, &VolSquare, &K, &T, &r, &Chi, &Theta, &Ita, &Rho, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(HestonCall(S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, StepSize));
}

static PyObject * Option_HestonPut(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, StepSize;
    if (!PyArg_ParseTuple(args, "dddddddddd", &S, &VolSquare, &K, &T, &r, &Chi, &Theta, &Ita, &Rho, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(HestonCall(S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, StepSize) + K*exp(-r*T) - S);
}

static PyObject * Option_HestonMixedGaussianCall(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize;
    if (!PyArg_ParseTuple(args, "dddddddddddddd", &S, &VolSquare, &K, &T, &r, &Chi, &Theta, &Ita, &Rho, &Up, &UpSigma, &Down, &DownSigma, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(HestonMixedGaussianCall(S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize));
}


static PyObject * Option_HestonMixedGaussianPut(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize;
    if (!PyArg_ParseTuple(args, "dddddddddddddd", &S, &VolSquare, &K, &T, &r, &Chi, &Theta, &Ita,
                        &Rho, &Up, &UpSigma, &Down, &DownSigma, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(HestonMixedGaussianCall(
        S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize) + K*exp(-r*T) - S);
}

static PyObject * Option_TwoRegimeHestonModelCall(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2, Theta2, Ita2, Rho2, StepSize;
    if (!PyArg_ParseTuple(args, "ddddddddddddddd", &S, &VolSquare, &K, &T1, &T2, &r, &Chi1, &Theta1, &Ita1, &Rho1, &Chi2, &Theta2, &Ita2, &Rho2, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(TwoRegimeHestonCall(S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2, Theta2, Ita2, Rho2, StepSize));
}

static PyObject * Option_TwoRegimeHestonModelPut(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2, Theta2, Ita2, Rho2, StepSize;
    if (!PyArg_ParseTuple(args, "ddddddddddddddd", &S, &VolSquare, &K, &T1, &T2, &r, &Chi1, &Theta1, &Ita1, &Rho1, &Chi2, &Theta2, &Ita2, &Rho2, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(TwoRegimeHestonCall(
        S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2, Theta2, Ita2, Rho2, StepSize) + K*exp(-r*(T1+T2)) - S);
}

static PyObject * Option_TwoRegimeHestonMixedGaussianCall(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2, Theta2, Ita2, Rho2, Up, UpSigma, Down, DownSigma, StepSize;
    if (!PyArg_ParseTuple(
            args, "ddddddddddddddddddd", &S, &VolSquare, &K, &T1, &T2, &r,
            &Chi1, &Theta1, &Ita1, &Rho1, &Chi2, &Theta2, &Ita2, &Rho2,
            &Up, &UpSigma, &Down, &DownSigma, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(TwoRegimeHestonMixedGaussianCall(
        S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2,
        Theta2, Ita2, Rho2, Up, UpSigma, Down, DownSigma, StepSize));
}

static PyObject * Option_TwoRegimeHestonMixedGaussianPut(PyObject *self, PyObject *args)
{
    double S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2, Theta2, Ita2, Rho2, Up, UpSigma, Down, DownSigma, StepSize;
    if (!PyArg_ParseTuple(
                          args, "ddddddddddddddddddd", &S, &VolSquare, &K, &T1, &T2, &r,
                          &Chi1, &Theta1, &Ita1, &Rho1, &Chi2, &Theta2, &Ita2, &Rho2,
                          &Up, &UpSigma, &Down, &DownSigma, &StepSize)){
        PyErr_SetString(SpamError, "Input is not valid");
        return NULL;
    }
    return PyFloat_FromDouble(TwoRegimeHestonMixedGaussianCall(
        S, VolSquare, K, T1, T2, r, Chi1, Theta1, Ita1, Rho1, Chi2,
        Theta2, Ita2, Rho2, Up, UpSigma, Down, DownSigma, StepSize)+ K*exp(-r*(T1+T2)) - S);
}

extern "C"{
    static PyMethodDef OptionMethods[] = {
        {"BSCall",  Option_BSCall, METH_VARARGS, "Calculate BS call option price"},
        {"BSPut",  Option_BSPut, METH_VARARGS, "Calculate BS put option price"},
        {"BSVega",  Option_BSVega, METH_VARARGS, "Calculate BS Vega"},
        {"BSCallIV",  Option_BSCallIV, METH_VARARGS, "Calculate BS call option implied vol"},
        {"BSPutIV",  Option_BSPutIV, METH_VARARGS, "Calculate BS put option implied vol"},
        {"HestonCall",  Option_HestonCall, METH_VARARGS, doc::HestonCall},
        {"HestonPut",  Option_HestonPut, METH_VARARGS, doc::HestonPut},
        {"HestonMixedGaussianCall", Option_HestonMixedGaussianCall, METH_VARARGS, doc::HestonMixedGaussianCall},
        {"HestonMixedGaussianPut", Option_HestonMixedGaussianPut, METH_VARARGS, doc::HestonMixedGaussianPut},
        {"TwoRegimeHestonCall", Option_TwoRegimeHestonModelCall, METH_VARARGS, doc::TwoRegimeHestonCall},
        {"TwoRegimeHestonPut", Option_TwoRegimeHestonModelPut, METH_VARARGS, doc::TwoRegimeHestonPut},
        {"TwoRegimeHestonMixedGaussianCall", Option_TwoRegimeHestonMixedGaussianCall, METH_VARARGS, "Calculate Two Regime Heston Gaussian call option price"},
        {"TwoRegimeHestonMixedGaussianPut", Option_TwoRegimeHestonMixedGaussianPut, METH_VARARGS, "Calculate Two Regime Heston Gaussian put option price"},
        {NULL, NULL, 0, NULL}        /* Sentinel */
    };
    
    static struct PyModuleDef PyHestonmodule = {
        PyModuleDef_HEAD_INIT,
        "PyHeston",   /* name of module */
        NULL, /* module documentation, may be NULL */
        -1,       /* size of per-interpreter state of the module,
                   or -1 if the module keeps state in global variables. */
        OptionMethods
    };
    
    PyMODINIT_FUNC
    PyInit_PyHeston(void)
    {
        return PyModule_Create(&PyHestonmodule);
    }
}

int main(){
    printf("Result %f\n", HestonMixedGaussianCall(200, 0, 200, 0.2, 0.1, 0.1, 0.1, 0.1, 0.1, 0.000001, 0, -0.000001, 0, 0.4));
    printf("Result %f\n", TwoRegimeHestonCall(200, 0, 200, 0.1, 0.05, 0, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.4));
    printf("Result %f\n", TwoRegimeHestonMixedGaussianCall(
        200, 0, 200, 0.1, 0.05, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0, -0.1, 0, 0.4));
    printf("Result %f\n", HestonCall(200, 0, 200, 0.2, 0.1, 0.1, 0.1, 0.1, 0.1, 0.4));
}







