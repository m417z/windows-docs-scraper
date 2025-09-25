# LongToUInt8 function

## Description

Converts a value of type **LONG** to a value of type **UINT8**.

## Parameters

### `lOperand` [in]

The value to convert.

### `pui8Result` [out]

The converted value.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of functions designed to provide type conversions and perform validity checks with minimal impact on performance.

**LongToByte** is an alias for this function.