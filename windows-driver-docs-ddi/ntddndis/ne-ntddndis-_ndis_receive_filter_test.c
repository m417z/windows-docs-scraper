typedef enum _NDIS_RECEIVE_FILTER_TEST {
  NdisReceiveFilterTestUndefined,
  NdisReceiveFilterTestEqual,
  NdisReceiveFilterTestMaskEqual,
  NdisReceiveFilterTestNotEqual,
  NdisReceiveFilterTestMaximum
} NDIS_RECEIVE_FILTER_TEST, *PNDIS_RECEIVE_FILTER_TEST;