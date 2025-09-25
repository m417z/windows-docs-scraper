typedef struct _IP_INTERFACE_INFO {
  LONG                 NumAdapters;
  IP_ADAPTER_INDEX_MAP Adapter[1];
} IP_INTERFACE_INFO, *PIP_INTERFACE_INFO;