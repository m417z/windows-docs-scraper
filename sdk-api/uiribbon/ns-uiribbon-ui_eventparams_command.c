typedef struct _UI_EVENTPARAMS_COMMAND {
  UINT             CommandID;
  PCWSTR           CommandName;
  UINT             ParentCommandID;
  PCWSTR           ParentCommandName;
  UINT             SelectionIndex;
  UI_EVENTLOCATION Location;
} UI_EVENTPARAMS_COMMAND;