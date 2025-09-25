typedef enum _DXGK_CHILD_DEVICE_HPD_AWARENESS {
  HpdAwarenessUninitialized,
  HpdAwarenessAlwaysConnected,
  HpdAwarenessNone,
  HpdAwarenessPolled,
  HpdAwarenessInterruptible
} DXGK_CHILD_DEVICE_HPD_AWARENESS, *PDXGK_CHILD_DEVICE_HPD_AWARENESS;