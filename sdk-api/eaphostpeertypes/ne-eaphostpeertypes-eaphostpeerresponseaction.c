typedef enum tagEapHostPeerResponseAction {
  EapHostPeerResponseDiscard = 0,
  EapHostPeerResponseSend,
  EapHostPeerResponseResult,
  EapHostPeerResponseInvokeUi,
  EapHostPeerResponseRespond,
  EapHostPeerResponseStartAuthentication,
  EapHostPeerResponseNone
} EapHostPeerResponseAction;