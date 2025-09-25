typedef struct _ACX_JACK_CONFIG {
  ULONG                Size;
  ULONG                Id;
  ULONG                Flags;
  PACX_JACK_CALLBACKS  Callbacks;
  ACX_JACK_DESCRIPTION Description;
} ACX_JACK_CONFIG, *PACX_JACK_CONFIG;