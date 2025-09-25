typedef struct _ACX_JACK_CALLBACKS {
  ULONG                                Size;
  PFN_ACX_JACK_RETRIEVE_PRESENCE_STATE EvtAcxJackRetrievePresenceState;
} ACX_JACK_CALLBACKS, *PACX_JACK_CALLBACKS;