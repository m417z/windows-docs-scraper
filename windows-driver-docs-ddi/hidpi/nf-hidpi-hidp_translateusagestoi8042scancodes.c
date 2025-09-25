NTSTATUS HidP_TranslateUsagesToI8042ScanCodes(
  [in]           PUSAGE                        ChangedUsageList,
  [in]           ULONG                         UsageListLength,
  [in]           HIDP_KEYBOARD_DIRECTION       KeyAction,
  [in, out]      PHIDP_KEYBOARD_MODIFIER_STATE ModifierState,
  [in]           PHIDP_INSERT_SCANCODES        InsertCodesProcedure,
  [in, optional] PVOID                         InsertCodesContext
);