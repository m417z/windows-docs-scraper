typedef struct _AVC_PIN_DESCRIPTOR {
  ULONG                  PinId;
  KSPIN_DESCRIPTOR       PinDescriptor;
  PFNAVCINTERSECTHANDLER IntersectHandler;
  PVOID                  Context;
} AVC_PIN_DESCRIPTOR, *PAVC_PIN_DESCRIPTOR;