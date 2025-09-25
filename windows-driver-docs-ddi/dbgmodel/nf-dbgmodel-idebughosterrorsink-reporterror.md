# IDebugHostErrorSink::ReportError

## Description

The ReportError method is a callback on the error sink to notify it that an error has occurred and allow the sink to route the error to whatever UI or mechanism is appropriate.

## Parameters

### `errClass`

An enumeration of type ErrorClass which indicates what class the error is (e.g.: warning or error)

### `hrError`

The HRESULT of the error which occurred.

### `message`

An optional message associated with the error.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDebugHostErrorSink interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosterrorsink)