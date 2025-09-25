# _NDIS_OID_REQUEST structure

## Description

To query or set OID information, NDIS submits NDIS_OID_REQUEST structures to filter drivers and
miniport drivers.

## Members

### `Header`

The [**NDIS\_OBJECT\_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the NDIS\_OID\_REQUEST structure. Set the **Type** member to NDIS\_OBJECT\_TYPE\_OID\_REQUEST. To indicate the version of the NDIS_OID_REQUEST structure, set the **Revision** member to one of the following values:

#### NDIS_OID_REQUEST_REVISION_2

Added the **SwitchId**, **VPortId**, and **Flags** members for NDIS 6.50.

Set the **Header** **Size** member to NDIS_SIZEOF_OID_REQUEST_REVISION_2.

#### NDIS_OID_REQUEST_REVISION_1

Original version for NDIS 6.0.

Set the **Header** **Size** member to NDIS_SIZEOF_OID_REQUEST_REVISION_1.

### `RequestType`

The request type as one of the
[NDIS_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_request_type) enumeration
values.

### `PortNumber`

The port to which the request is sent. If the port is unknown or default, this member is
zero.

### `Timeout`

A time-out, in seconds, for the request. NDIS can reset the driver or cancel the request if the
time-out expires before the driver completes the request.

### `RequestId`

An identifier for the request. If a miniport driver must complete a request immediately and it
completes the request with a status of NDIS_STATUS_INDICATION_REQUIRED, the miniport driver uses this
**RequestId** value to set the
**RequestId** member of the associated
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure.

NDIS or overlying drivers can also use the
**RequestId** to cancel a request. When a miniport driver receives a
cancellation request, the miniport driver cancels any pending requests with a matching
**RequestId**. If
**RequestId** is zero, the miniport driver can ignore this member. For more
information about status indications, see the following Remarks section.

### `RequestHandle`

A handle that identifies the source that issued the OID request. If a miniport driver must complete
the request immediately and completes the request with a status of NDIS_STATUS_INDICATION_REQUIRED, the
miniport driver uses this
**RequestHandle** value to set the
**DestinationHandle** member of the associated NDIS_STATUS_INDICATION
structure. In this case, NDIS will send only the subsequent status indication to the source that issued
the OID request.

For more information about status indications, see the following Remarks section.

### `DATA`

A union that defines the request data. The information in the data varies according to the type of
request as specified by the
**RequestType** member. The following member structures are specified:

### `DATA.Oid`

### `DATA.QUERY_INFORMATION`

This structure contains the parameters for an **NdisRequestQueryInformation** or
**NdisRequestQueryStatistics** request type. This structure is specified as follows:

```

struct _QUERY
  {
    NDIS_OID    Oid;
    PVOID       InformationBuffer;
    UINT        InformationBufferLength;
    UINT        BytesWritten;
    UINT        BytesNeeded;
  } QUERY_INFORMATION;

```

### `DATA.QUERY_INFORMATION.Oid`

The object identifier of the requested operation. The value is an OID_
*XXX* code.

### `DATA.QUERY_INFORMATION.InformationBuffer`

A pointer to a buffer into which the underlying driver or NDIS returns the requested information
for query-information requests.

### `DATA.QUERY_INFORMATION.InformationBufferLength`

The size, in bytes, of the buffer at
**InformationBuffer**. The value at
**Oid** determines the value appropriate to this member.

### `DATA.QUERY_INFORMATION.BytesWritten`

The number of bytes that the underlying driver or NDIS transfers into the buffer at
**InformationBuffer** for query-information requests. If the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function returns
NDIS_STATUS_INVALID_LENGTH, the value of this member is meaningless.

### `DATA.QUERY_INFORMATION.BytesNeeded`

The number of bytes that are required to return query information requested by the given OID_
*XXX* code.

If
**NdisOidRequest** returns NDIS_STATUS_SUCCESS, the value of this member is
meaningless. If the
**InformationBufferLength** is too small for the given OID_
*XXX* on a query request, this member indicates how large a buffer is
required to satisfy the request.

### `DATA.SET_INFORMATION`

This structure contains the parameters for an **NdisRequestSetInformation** request type. This structure
is specified as follows:

```

struct _SET
  {
    NDIS_OID    Oid;
    PVOID       InformationBuffer;
    UINT        InformationBufferLength;
    UINT        BytesRead;
    UINT        BytesNeeded;
  } SET_INFORMATION;

```

### `DATA.SET_INFORMATION.Oid`

The object identifier of the requested operation. The value is an OID_
*XXX* code.

### `DATA.SET_INFORMATION.InformationBuffer`

A pointer to a buffer from which the underlying driver reads caller-supplied information for
set-information requests.

### `DATA.SET_INFORMATION.InformationBufferLength`

The size, in bytes, of the buffer at
**InformationBuffer**. The value at
**Oid** determines the value appropriate to this member.

### `DATA.SET_INFORMATION.BytesRead`

The number of bytes that the underlying driver read from the buffer at
**InformationBuffer** for set-information requests.

### `DATA.SET_INFORMATION.BytesNeeded`

The number of bytes that are required to carry out the set operation requested by the given OID_
*XXX* code.

If
**NdisOidRequest** returns NDIS_STATUS_SUCCESS, the value of this member is
meaningless. If the buffer at
**InformationBuffer** does not contain sufficient data for the given OID_
*XXX* on a set request, this member indicates how much data is required.

### `DATA.METHOD_INFORMATION`

This structure contains the parameters for an **NdisRequestMethod** request type. This structure is
specified as follows:

```

struct _METHOD
  {
    NDIS_OID            Oid;
    PVOID               InformationBuffer;
    ULONG               InputBufferLength;
    ULONG               OutputBufferLength;
    ULONG               MethodId;
    UINT                BytesWritten;
    UINT                BytesRead;
    UINT                BytesNeeded;
  } METHOD_INFORMATION;

```

### `DATA.METHOD_INFORMATION.Oid`

The object identifier of the requested operation. The value is an OID_
*XXX* code.

### `DATA.METHOD_INFORMATION.InformationBuffer`

A pointer to a buffer into which the underlying driver or NDIS returns the requested information
for query operations or from which the underlying driver reads caller-supplied information for set
operations. These operations are specific to the type of **NdisRequestMethod** request type that is being
made.

**Note** This buffer is used for both set-information and query-information requests. As
a result, data in the buffer for the set-information request would be overwritten by data that is
returned for the query-information request. The exact usage depends on the requested operation as
specified by the
**Oid** member.

### `DATA.METHOD_INFORMATION.InputBufferLength`

The size, in bytes, of the readable data in the buffer at
**InformationBuffer**. The value at
**Oid** determines the value appropriate to this member.

### `DATA.METHOD_INFORMATION.OutputBufferLength`

The number of bytes in the buffer at
**InformationBuffer** that the driver can write.

### `DATA.METHOD_INFORMATION.MethodId`

The method to run for a method OID. A method OID request can support multiple operations as
defined by
**MethodId**. It can be any value that is greater or equal to zero. Zero
indicates the default method. NDIS can define public method OIDs with some predefined methods.
Miniport drivers can define custom method OIDs. For more information about custom OIDs, see
[OID_GEN_SUPPORTED_GUIDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-guids).

### `DATA.METHOD_INFORMATION.BytesWritten`

The number of bytes that the underlying driver or NDIS transfers into the buffer at
**InformationBuffer** for query-information requests. If the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function returns
NDIS_STATUS_INVALID_LENGTH, the value of this member is meaningless.

For method OIDs,
**BytesWritten** should be less than or equal to the value in the
**OutputBufferLength** member.

### `DATA.METHOD_INFORMATION.BytesRead`

The number of bytes that the underlying driver read from the buffer at
**InformationBuffer** for set-information requests.

For method OIDs,
**BytesRead** should be less than or equal to the value in the
**InputBufferLength** member.

### `DATA.METHOD_INFORMATION.BytesNeeded`

The number of bytes that are required to return query information or to carry out the set
operation requested by the given OID_
*XXX* code.

If
**NdisOidRequest** returns NDIS_STATUS_SUCCESS, the value of this member is
meaningless. If the
**InformationBufferLength** is too small for the given OID_
*XXX* on a query, this member indicates how large a buffer is required to
satisfy the request. If the buffer at
**InformationBuffer** does not contain sufficient data for the given OID_
*XXX* on a set, this member indicates how much data is required.

### `_REQUEST_DATA`

### `NdisReserved`

An area that is reserved for NDIS.

### `MiniportReserved`

An area that is reserved for the miniport driver.

### `SourceReserved`

An area that is reserved for the originating driver. Reserved for the allocator of the
NDIS_OID_REQUEST structure. This is usually an NDIS protocol driver or an NDIS filter driver.

### `SupportedRevision`

The revision of an NDIS structure that was supported by an NDIS 6.0 or later driver when it
handled an OID request. A revisioned structure is any NDIS 6.0 structure that has an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure inside it.
When the driver succeeds in setting an OID, it must set
**SupportedRevision** to the revision number of the structure that it
supported. For more information about NDIS version information, see
[Specifying NDIS Version
Information](https://learn.microsoft.com/windows-hardware/drivers/network/specifying-ndis-version-information).

### `Reserved1`

Reserved for future use.

### `Reserved2`

Reserved for future use.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that identifies the switch on which the target VPort, specified by **VPortId**, is running.

> [!NOTE]
> This field is supported in NDIS 6.50 and later.

### `VPortId`

An NDIS_NIC_SWITCH_VPORT_ID value that identifies the VPort that this OID request is targeting. This field is considered valid only if the **NDIS_OID_REQUEST_FLAGS_VPORT_ID_VALID** flag is set.

> [!NOTE]
> This field is supported in NDIS 6.50 and later.

### `Flags`

A ULONG value that contains a bitwise OR of flags for this OID request. Currently, these flags are supported:

| Flag | Value | Description |
| --- | --- | --- |
| NDIS_OID_REQUEST_FLAGS_VPORT_ID_VALID | 0x0001 | When this flag is set, the **VportId** member is considered valid and identifies the VPort to which the OID is targeted. If this flag is not set, then the OID is for the miniport adapter itself. |

> [!NOTE]
> This field is supported in NDIS 6.50 and later.

## Remarks

A protocol driver or a filter driver should allocate nonpaged memory for the buffer at
**InformationBuffer** and for the NDIS_OID_REQUEST structure. Using data that
is allocated from paged memory can cause fatal page faults because the underlying drivers run at IRQL =
DISPATCH_LEVEL to carry out the requested operation.

NDIS_OID_REQUEST contains a DATA substructure for each type of operation that a protocol driver can
request of an underlying driver. Before calling
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest), the protocol driver fills
in the relevant members of the substructure that represents the query or set operation it specified in
the
**Oid** member. NDIS or the underlying driver fills in the remaining members
before it returns control to the caller.

Some OID requests allow a miniport driver to provide an OID completion status with a status
indication. In this case, the miniport driver returns NDIS_STATUS_INDICATION_REQUIRED for the completion
status of the OID request. A miniport driver cannot return this status unless the particular OID allows
it. To determine if this status is allowed, see the OID reference page.

If a status indication is associated with an OID request where the miniport driver returned
NDIS_STATUS_INDICATION_REQUIRED, the driver making the status indication must set the
**DestinationHandle** and
**RequestId** members in the
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure.

In this case, the driver sets the
**DestinationHandle** and
**RequestId** members to the values from the
**RequestHandle** and
**RequestId** members in the NDIS_OID_REQUEST structure, respectively.

For example, in wireless networking, the processing of an OID request can take a very long time to
complete. In this case, the miniport driver can complete the OID request immediately and provide a status
indication later to provide the final result for the OID request.

The
**NdisRequestGeneric***n*(1-4) types are available for miniport drivers that create their own internal
requests. To implement such a request, a miniport driver assigns an internal variable to one of these
generic types.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_request_type)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[OID_GEN_SUPPORTED_GUIDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-guids)