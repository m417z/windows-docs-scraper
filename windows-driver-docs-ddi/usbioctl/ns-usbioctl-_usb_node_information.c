typedef struct _USB_NODE_INFORMATION {
  USB_HUB_NODE NodeType;
  union {
    USB_HUB_INFORMATION       HubInformation;
    USB_MI_PARENT_INFORMATION MiParentInformation;
  } u;
} USB_NODE_INFORMATION, *PUSB_NODE_INFORMATION;