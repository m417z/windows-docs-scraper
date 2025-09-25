typedef struct _UI_EVENTPARAMS {
  UI_EVENTTYPE EventType;
  union {
    INT32                  Modes;
    UI_EVENTPARAMS_COMMAND Params;
  };
} UI_EVENTPARAMS;