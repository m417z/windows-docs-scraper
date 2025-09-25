typedef struct RILUICCSLOTINFO {
  DWORD            cbSize;
  DWORD            dwParams;
  DWORD            dwNumOfUiccSlots;
  RILUICCSLOTSTATE dwSlotState[1];
} RILUICCSLOTINFO, *LPRILUICCSLOTINFO;