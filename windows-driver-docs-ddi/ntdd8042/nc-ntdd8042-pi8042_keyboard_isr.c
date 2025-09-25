PI8042_KEYBOARD_ISR Pi8042KeyboardIsr;

BOOLEAN Pi8042KeyboardIsr(
  [in]  PVOID IsrContext,
  [in]  PKEYBOARD_INPUT_DATA CurrentInput,
  [in]  POUTPUT_PACKET CurrentOutput,
  [in]  UCHAR StatusByte,
  [in]  PUCHAR Byte,
  [out] PBOOLEAN ContinueProcessing,
  [in]  PKEYBOARD_SCAN_STATE ScanState
)
{...}