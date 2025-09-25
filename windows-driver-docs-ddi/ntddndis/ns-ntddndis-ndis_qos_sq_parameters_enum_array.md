## Description

**NDIS_QOS_SQ_PARAMETERS_ENUM_ARRAY** is not currently used and has been updated to **NDIS_QOS_SQ_ARRAY** for NDIS 6.45 and later.

The **NDIS_QOS_SQ_ARRAY** structure is used to enumerate NDIS Quality of Service (QoS) Scheduler Queues (SQs) for parameters and stats. This structure is returned in the OID query requests [OID_QOS_OFFLOAD_ENUM_SQS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-enum-sqs) and [OID_QOS_OFFLOAD_SQ_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-sq-stats).

To view the header definition for **NDIS_QOS_SQ_ARRAY**, see [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters_enum_array#remarks).

## Syntax

```cpp
#define NDIS_QOS_SQ_PARAMETERS_ARRAY_REVISION_1        1

#if (NDIS_SUPPORT_NDIS684)
#define NDIS_QOS_SQ_ARRAY_REVISION_1                   1
#endif // (NDIS_SUPPORT_NDIS684)

typedef struct _NDIS_QOS_SQ_PARAMETERS_ENUM_ARRAY {
    NDIS_OBJECT_HEADER                 Header;
    ULONG                              Flags;
    NDIS_QOS_SQ_TYPE                   SqType;
    NDIS_QOS_SQ_ID                     FirstSqId;
    ULONG                              MaxSqsToReturn;
#if (NDIS_SUPPORT_NDIS684)
    union {
        ULONG                          SqArrayOffset;
        ULONG                          SqParamsArrayOffset;
    };
    union {
        ULONG                          SqArrayNumElements;
        ULONG                          SqParamsArrayNumElements;
    };
    union {
        ULONG                          SqArrayElementSize;
        ULONG                          SqParamsArrayElementSize;
    };
#else
    ULONG                              SqParamsArrayOffset;
    ULONG                              SqParamsArrayNumElements;
    ULONG                              SqParamsArrayElementSize;
#endif // (NDIS_SUPPORT_NDIS684)
} NDIS_QOS_SQ_PARAMETERS_ENUM_ARRAY, *PNDIS_QOS_SQ_PARAMETERS_ENUM_ARRAY;

#if (NDIS_SUPPORT_NDIS684)
typedef struct _NDIS_QOS_SQ_PARAMETERS_ENUM_ARRAY NDIS_QOS_SQ_ARRAY, *PNDIS_QOS_SQ_ARRAY;
#define NDIS_SIZEOF_QOS_SQ_ARRAY_REVISION_1                     \
    RTL_SIZEOF_THROUGH_FIELD(NDIS_QOS_SQ_ARRAY, SqArrayElementSize)
#endif // (NDIS_SUPPORT_NDIS684)

#define NDIS_SIZEOF_QOS_SQ_PARAMETERS_ENUM_ARRAY_REVISION_1     \
    RTL_SIZEOF_THROUGH_FIELD(NDIS_QOS_SQ_PARAMETERS_ENUM_ARRAY, SqParamsArrayElementSize)
```

## Members

### `Header`

The type, revision, and size of the **NDIS_QOS_SQ_STATS** structure. This member is formatted as an [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT, the **Revision** member to NDIS_QOS_SQ_PARAMETERS_ARRAY_REVISION_1, and the **Size** member to NDIS_SIZEOF_QOS_SQ_PARAMETERS_ARRAY_REVISION_1.

### `Flags`

Not used in NDIS_QOS_SQ_PARAMETERS_ARRAY_REVISION_1. The caller sets this field to **zero**.

### `SqType`

An [**NDIS_QOS_SQ_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-ndis_qos_sq_type) that contains the type of this SQ. This can be **NdisQSQosSqSQTypeStandard** from the enum definition of **NDIS_QOS_SQ_TYPE**.

### `FirstSqId`

An NDIS_QOS_SQ_ID that specifies the first SQ ID of this array.

### `MaxSqsToReturn`

The maximum number of SQs contained in this array.

### `SqArrayOffset`

The byte offset from the beginning of this structure that marks the beginning of an array. The type of each element depends on the OID request:

|OID |Element type |
|----------|-----------|
|[OID_QOS_OFFLOAD_ENUM_SQS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-enum-sqs) |[**NDIS_QOS_SQ_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters) |
|[OID_QOS_OFFLOAD_SQ_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-sq-stats)|[**NDIS_QOS_SQ_STATS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_stats) |

### `SqParamsArrayOffset`

This field is not used in **NDIS_QOS_SQ_ARRAY**.

### `SqArrayNumElements`

The number of elements in this array specified by **SQArrayOffset**.

### `SqParamsArrayNumElements`

This field is not used in **NDIS_QOS_SQ_ARRAY**.

### `SqArrayElementSize`

The size of each element in this array.

### `SqParamsArrayElementSize`

This field is not used in **NDIS_QOS_SQ_ARRAY**.

## Remarks

The **NDIS_QOS_SQ_ARRAY** structure is used to enumerate QoS SQs for parameters and stats.

### Syntax

```cpp
typedef struct _NDIS_QOS_SQ_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  NDIS_QOS_SQ_TYPE   SqType;
  NDIS_QOS_SQ_ID     FirstSqId;
  ULONG              MaxSqsToReturn;
  ULONG              SqArrayOffset;
  ULONG              SqArrayNumElements;
  ULONG              SqArrayElementSize;
} NDIS_QOS_SQ_ARRAY, *PNDIS_QOS_SQ_ARRAY;
```

The member descriptions above explain how to set the **NDIS_QOS_SQ_ARRAY** fields.

**NDIS_QOS_SQ_ARRAY** is returned in the OID query request [OID_QOS_OFFLOAD_ENUM_SQS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-enum-sqs), which enumerates the SQs created on a NIC switch

**NDIS_QOS_SQ_ARRAY** is also returned in the OID query request [OID_QOS_OFFLOAD_SQ_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-sq-stats), used to obtain a list of SQs currently present on a miniport adapter and their stat counters.

## See also

[OID_QOS_OFFLOAD_ENUM_SQS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-enum-sqs)

[OID_QOS_OFFLOAD_SQ_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-sq-stats)

[**NDIS_QOS_SQ_STATS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_stats)

[**NDIS_QOS_SQ_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-ndis_qos_sq_type)

[**NDIS_QOS_SQ_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters)

[**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)