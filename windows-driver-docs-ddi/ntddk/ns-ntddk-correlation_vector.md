# CORRELATION_VECTOR structure

## Description

Store the [correlation vector](https://github.com/Microsoft/CorrelationVector) that is used to reference events and the generated logs
for diagnostic purposes.

## Members

### `Version`

The version of the correlation vector. Possible values are:

* RTL_CORRELATION_VECTOR_VERSION_1
* RTL_CORRELATION_VECTOR_VERSION_2
* RTL_CORRELATION_VECTOR_VERSION_CURRENT

### `Vector`

An array CHARs that represents the correlation vector.