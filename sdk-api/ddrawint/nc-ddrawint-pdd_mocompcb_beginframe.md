## Description

The **DdMoCompBeginFrame** callback function starts decoding a new frame.

## Parameters

### `unnamedParam1`

Points to a [DD_BEGINMOCOMPFRAMEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_beginmocompframedata) structure that contains the information needed to start decoding a new frame.

## Return value

**DdMoCompBeginFrame** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support motion compensation must implement **DdMoCompBeginFrame**.

DirectDraw ensures that begin and end frames will be properly paired.

## See also

[DD_BEGINMOCOMPFRAMEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_beginmocompframedata)