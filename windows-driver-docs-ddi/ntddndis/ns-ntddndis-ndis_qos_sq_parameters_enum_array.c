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