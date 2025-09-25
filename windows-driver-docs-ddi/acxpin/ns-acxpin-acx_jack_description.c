typedef struct _ACX_JACK_DESCRIPTION {
  ULONG                    ChannelMapping;
  ULONG                    Color;
  ACX_JACK_CONNECTION_TYPE ConnectionType;
  ACX_JACK_GEO_LOCATION    GeoLocation;
  ACX_JACK_GEN_LOCATION    GenLocation;
  ACX_JACK_PORT_CONNECTION PortConnection;
} ACX_JACK_DESCRIPTION, *PACX_JACK_DESCRIPTION;