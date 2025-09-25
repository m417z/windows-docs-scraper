# PFND3DDDI_QUERYDLISTFORAPPLICATION callback function

## Description

The PFND3DDDI_QUERYDLISTFORAPPLICATION callback function queries a DList for an application.

## Parameters

### `unnamedParam1` [out]

Indicates whether or not there is an application in the DList.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3DDDI_QUERYDLISTFORAPPLICATION Pfnd3dddiQuerydlistforapplication;

// Definition

HRESULT Pfnd3dddiQuerydlistforapplication
(
	BOOL *
)
{...}

```