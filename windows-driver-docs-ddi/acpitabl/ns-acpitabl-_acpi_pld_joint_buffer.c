typedef struct _ACPI_PLD_JOINT_BUFFER {
  UINT32 Revision : 5;
  UINT32 JointType : 4;
  UINT32 SourceEdge : 3;
  UINT32 TargetCabinetNumber : 8;
  UINT32 TargetPanel : 3;
  UINT32 TargetEdge : 3;
  UINT32 Reserved1 : 5;
  UINT32 MovementOrientation : 1;
  UINT32 ForwardMovementRange : 16;
  UINT32 BackwardMovementRange : 16;
  UINT32 HorizontalOffset : 16;
  UINT32 VerticalOffset : 16;
  UINT32 GapOffset : 16;
  UINT32 Rotation : 9;
  UINT32 Reserved2 : 7;
} ACPI_PLD_JOINT_BUFFER, *PACPI_PLD_JOINT_BUFFER;