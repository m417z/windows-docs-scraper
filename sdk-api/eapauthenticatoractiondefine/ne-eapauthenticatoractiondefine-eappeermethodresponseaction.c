typedef enum tagEapPeerMethodResponseAction {
  EapPeerMethodResponseActionDiscard = 0,
  EapPeerMethodResponseActionSend,
  EapPeerMethodResponseActionResult,
  EapPeerMethodResponseActionInvokeUI,
  EapPeerMethodResponseActionRespond,
  EapPeerMethodResponseActionNone
} EapPeerMethodResponseAction;