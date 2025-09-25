# EvtGetChannelConfigProperty function

## Description

Gets the specified channel configuration property.

## Parameters

### `ChannelConfig` [in]

A handle to the channel's configuration properties that the [EvtOpenChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelconfig) function returns.

### `PropertyId` [in]

The identifier of the channel property to retrieve. For a list of property identifiers, see the [EVT_CHANNEL_CONFIG_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_config_property_id) enumeration.

### `Flags` [in]

Reserved. Must be zero.

### `PropertyValueBufferSize` [in]

The size of the *PropertyValueBuffer* buffer, in bytes.

### `PropertyValueBuffer` [in]

A caller-allocated buffer that will receive the configuration property. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. You can set this parameter to **NULL** to determine the required buffer size.

### `PropertyValueBufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## See also

[EvtOpenChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelconfig)