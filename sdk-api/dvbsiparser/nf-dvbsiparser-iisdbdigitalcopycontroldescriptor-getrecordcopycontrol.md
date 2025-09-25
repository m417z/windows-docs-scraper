# IIsdbDigitalCopyControlDescriptor::GetRecordCopyControl

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets copy control data from a specified component in an Integrated Services Digital Broadcasting (ISDB) digital copy control descriptor. When the component_control_flag field in the descriptor is set to 1, the control information is specified in each component of the descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the record number for the component,
indexed from zero. Call the [IIsdbDigitalCompyControlDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbdigitalcopycontroldescriptor-getcountofrecords) method to get the number of records in the digital copy control descriptor.

### `pbComponentTag` [out]

Receives the tag identifying the component. This value is the same as the component tag in the stream
identifier descriptor and the component descriptor.

### `pbDigitalRecordingControlData` [out]

Receives the two-bit code that indicates the type of copy control. This code can have any of the following values.

| Value | Meaning |
| --- | --- |
| 00 | Unrestricted copies allowed. |
| 01 | When *pbCopyControlType* parameter is 11, not used; when *pbCopyControlType* is 01, copying forbidden. |
| 10 | Can be copied only once. |
| 11 | Copying forbidden. |

### `pbCopyControlType` [out]

Receives data that defines output control options for digital copying.

| Value | Meaning |
| --- | --- |
| 00 | Undefined. |
| 01 | Output by encoding to serial interface. |
| 10 | Undefined. |
| 11 | Output by not encoding to serial interface. |

### `pbAPSControlData` [out]

Receives data that defines output control options for analog copying when the value of the *pbCopyControlType* parameter is 01.

| Value | Meaning |
| --- | --- |
| 00 | Undefined. |
| 01 | Output with pseudosync pulse |
| 10 | Output with pseudosync pulse + two-line reversed division burst insertion. |
| 11 | Output with pseudosync pulse + four-line reversed division burst insertion. |

### `pbMaximumBitrate` [out]

Receives the maximum transmission rate for transport stream packets, in units of 250 kbps.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDigitalCompyControlDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbdigitalcopycontroldescriptor-getcountofrecords)

[IIsdbDigitalCopyControlDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdigitalcopycontroldescriptor)