MI_INLINE MI_Result MI_Application_NewSession(
  [in]           MI_Application        *application,
  [in, optional] const MI_Char         *protocol,
  [in, optional] const MI_Char         *destination,
  [in, optional] MI_DestinationOptions *options,
  [in, optional] MI_SessionCallbacks   *callbacks,
                 MI_Instance           **extendedError,
  [out]          MI_Session            *session
);