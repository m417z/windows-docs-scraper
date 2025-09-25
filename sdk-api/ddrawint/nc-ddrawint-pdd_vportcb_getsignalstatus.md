## Description

The *DdVideoPortGetSignalStatus* callback function retrieves the status of the video signal currently being presented to the hardware video port.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTSIGNALDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportsignaldata) structure that contains the information required for the driver to retrieve the status of the video signal.

## Return value

*DdVideoPortGetSignalStatus* returns one of the following callback codes:

## Remarks

DirectDraw drivers that support VPE must implement *DdVideoPortGetSignalStatus*.

The driver should determine whether a valid signal is coming in to the hardware video port and report the result in the **dwStatus** member of the DD_GETVPORTSIGNALDATA structure at *lpGetSignalStatus*.

## See also

[DD_GETVPORTSIGNALDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportsignaldata)