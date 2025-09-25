# IBDA_AUX::EnumCapability

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the capabilities of an auxiliary connector, specified by index.

## Parameters

### `dwIndex` [in]

The zero-based index of the auxiliary connector. To get the number of connectors on the device, call [IBDA_AUX::QueryCapabilities](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_aux-querycapabilities).

### `dwInputID` [out]

Receives a unique identifier for the auxiliary connector.

### `pConnectorType` [out]

Receives a GUID that specifies the type of connector.

| Value | Meaning |
| --- | --- |
| **PBDA_AUX_CONNECTOR_TYPE_Composite** | Composite video connector. |
| **PBDA_AUX_CONNECTOR_TYPE_SVideo** | S-Video connector. |

### `ConnTypeNum` [out]

Receives a numeric identifier for the auxiliary input.

### `NumVideoStds` [out]

Receives the number of analog video standards that the connector supports.

### `AnalogStds` [out]

Receives a bitwise **OR** of flags from the [AnalogVideoStandard](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard) enumeration, specifying which analog video standards the connector supports.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must call the [IBDA_AUX::QueryCapabilities](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_aux-querycapabilities) method before calling this method.

## See also

[IBDA_AUX](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_aux)