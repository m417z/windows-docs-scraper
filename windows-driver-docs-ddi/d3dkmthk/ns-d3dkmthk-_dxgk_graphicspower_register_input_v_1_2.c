typedef struct _DXGK_GRAPHICSPOWER_REGISTER_INPUT_V_1_2 {
  ULONG                         Version;
  PVOID                         PrivateHandle;
  PDXGK_POWER_NOTIFICATION      PowerNotificationCb;
  PDXGK_REMOVAL_NOTIFICATION    RemovalNotificationCb;
  PDXGK_FSTATE_NOTIFICATION     FStateNotificationCb;
  PDXGK_INITIAL_COMPONENT_STATE InitialComponentStateCb;
} DXGK_GRAPHICSPOWER_REGISTER_INPUT_V_1_2, *PDXGK_GRAPHICSPOWER_REGISTER_INPUT_V_1_2;