MI_Deserializer_ClassObjectNeeded MiDeserializerClassobjectneeded;

MI_Result MiDeserializerClassobjectneeded(
  [in, optional] void *context,
  [in, optional] const MI_Char *serverName,
  [in, optional] const MI_Char *namespaceName,
  [in, optional] const MI_Char *className,
  [out]          MI_Class **requestedClassObject
)
{...}