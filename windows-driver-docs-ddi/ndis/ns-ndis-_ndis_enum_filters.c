typedef struct _NDIS_ENUM_FILTERS {
  NDIS_OBJECT_HEADER    Header;
  ULONG                 Flags;
  ULONG                 NumberOfFilters;
  ULONG                 OffsetFirstFilter;
  NDIS_FILTER_INTERFACE Filter[1];
} NDIS_ENUM_FILTERS, *PNDIS_ENUM_FILTERS;