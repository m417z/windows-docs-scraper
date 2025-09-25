typedef struct {
  WSD_ENDPOINT_REFERENCE     *EndTo;
  WSD_EVENTING_DELIVERY_MODE *Delivery;
  WSD_EVENTING_EXPIRES       *Expires;
  WSD_EVENTING_FILTER        *Filter;
  WSDXML_ELEMENT             *Any;
} REQUESTBODY_Subscribe;