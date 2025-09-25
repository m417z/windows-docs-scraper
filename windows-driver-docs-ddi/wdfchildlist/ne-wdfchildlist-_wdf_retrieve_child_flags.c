typedef enum _WDF_RETRIEVE_CHILD_FLAGS {
  WdfRetrieveUnspecified = 0x0000,
  WdfRetrievePresentChildren = 0x0001,
  WdfRetrieveMissingChildren = 0x0002,
  WdfRetrievePendingChildren = 0x0004,
  WdfRetrieveAddedChildren = (WdfRetrievePresentChildren | WdfRetrievePendingChildren),
  WdfRetrieveAllChildren = (WdfRetrievePresentChildren | WdfRetrievePendingChildren | WdfRetrieveMissingChildren)
} WDF_RETRIEVE_CHILD_FLAGS;