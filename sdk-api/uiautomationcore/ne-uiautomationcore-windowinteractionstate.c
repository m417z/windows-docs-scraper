typedef enum WindowInteractionState {
  WindowInteractionState_Running = 0,
  WindowInteractionState_Closing = 1,
  WindowInteractionState_ReadyForUserInteraction = 2,
  WindowInteractionState_BlockedByModalWindow = 3,
  WindowInteractionState_NotResponding = 4
} ;