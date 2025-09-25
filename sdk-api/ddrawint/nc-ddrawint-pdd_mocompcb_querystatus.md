## Description

The **DdMoCompQueryStatus** callback function queries the status of the most recent rendering operation to the specified surface.

## Parameters

### `unnamedParam1`

Points to a [DD_QUERYMOCOMPSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_querymocompstatusdata) structure that contains the information needed to query the status.

## Return value

**DdMoCompQueryStatus** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support motion compensation must implement **DdMoCompQueryStatus**.

## See also

[DD_QUERYMOCOMPSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_querymocompstatusdata)