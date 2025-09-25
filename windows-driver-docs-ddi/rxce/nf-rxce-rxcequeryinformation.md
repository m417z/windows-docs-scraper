# RxCeQueryInformation function

## Description

**RxCeQueryInformation** queries information about a connection in a caller-allocated buffer.

## Parameters

### `pVc` [in]

A pointer to the virtual circuit associated with this connection.

### `InformationClass` [in]

The desired information class for this query type. The value specified for *InformationClass* determines the type of information that is returned. This parameter is an enumeration defined in *rxcehdlr.h* and can be one of the following values:

#### RxCeTransportProviderInformation

Query the transport for provider information. An RXCE_TRANSPORT_PROVIDER_INFO structure is copied to the *pInformation* buffer on success. Note that RXCE_TRANSPORT_PROVIDER_INFO is a typedef for TDI_PROVIDER_INFO.

#### RxCeConnectionInformation

Query For information about the connection. An RXCE_CONNECTION_INFORMATION structure is copied to the *pInformation* buffer on success. Note that RXCE_CONNECTION_INFORMATION is a typedef for TDI_CONNECTION_INFORMATION.

#### RxCeConnectionEndpointInformation

Query the transport For information about the connection endpoint. An RXCE_CONNECTION_INFO structure is copied to the *pInformation* buffer on success. Note that RXCE_CONNECTION_INFO is a typedef for TDI_CONNECTION_INFO.

#### RxCeRemoteAddressInformation

Query the transport For information about the remote address. A TDI_ADDRESS_INFO structure is copied to the *pInformation* buffer on success.

### `pInformation` [out]

The caller-supplied buffer for returning information.

### `Length` [in]

The length of the buffer.

## Return value

**RxCeQueryInformation** returns STATUS_SUCCESS on success or one of the following warning or error codes:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_OVERFLOW** | This specified *length* of the output buffer pointed to by *pInformation* was not large enough to receive the information requested by the *InformationClass* query type. |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | This value can be returned for any of the following conditions:<br><br>The *pVC* parameter passed to this routine was invalid.<br><br>The connection, address, or transport defined for this virtual circuit was invalid.<br><br>The *InformationClass* for this query type was not one of the allowed values. |

## Remarks

**RxCeQueryInformation** returns information for a given virtual circuit. The only values for *InformationClass* that can be specified when calling **RxCeQueryInformation** are the following:

RxCeTransportProviderInformation

RxCeConnectionInformation

RxCeConnectionEndpointInformation

RxCeRemoteAddressInformation

For some values of *InformationClass*, **RxCeQueryInformation** calls **TdiBuildQueryInformation** and TDI to retrieve the requested information.

## See also

[RxCeQueryAdapterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcequeryadapterstatus)

[RxCeQueryTransportInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcequerytransportinformation)