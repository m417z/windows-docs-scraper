# ConvertException function

## Description

Trap and convert all exceptions coming out of a functor to an appropriate HRESULT.

C++ Specific API Helper.

## Parameters

### `fn`

An HRESULT returning functor. If the functor throws an exception, the exception will be caught and converted to an HRESULT.

## Return value

This function returns HRESULT.

## Remarks

## See also