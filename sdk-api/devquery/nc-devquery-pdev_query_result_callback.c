PDEV_QUERY_RESULT_CALLBACK PdevQueryResultCallback;

VOID PdevQueryResultCallback(
  HDEVQUERY hDevQuery,
  PVOID pContext,
  const DEV_QUERY_RESULT_ACTION_DATA *pActionData
)
{...}