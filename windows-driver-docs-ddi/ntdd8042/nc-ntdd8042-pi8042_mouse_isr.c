PI8042_MOUSE_ISR Pi8042MouseIsr;

BOOLEAN Pi8042MouseIsr(
  [in]      PVOID IsrContext,
  [in]      PMOUSE_INPUT_DATA CurrentInput,
  [in]      POUTPUT_PACKET CurrentOutput,
  [in]      UCHAR StatusByte,
  [in]      PUCHAR Byte,
  [in, out] PBOOLEAN ContinueProcessing,
  [in]      PMOUSE_STATE MouseState,
  [in]      PMOUSE_RESET_SUBSTATE ResetSubState
)
{...}