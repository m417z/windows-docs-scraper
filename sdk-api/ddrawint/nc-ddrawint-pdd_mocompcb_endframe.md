## Description

The **DdMoCompEndFrame** callback function completes a decoded frame.

## Parameters

### `unnamedParam1`

Points to a [DD_ENDMOCOMPFRAMEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_endmocompframedata) structure that contains the information needed to complete the decoded frame.

## Return value

**DdMoCompEndFrame** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support motion compensation must implement **DdMoCompEndFrame**.

DirectDraw ensures that begin and end frames will be properly paired.

## See also

[DD_ENDMOCOMPFRAMEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_endmocompframedata)