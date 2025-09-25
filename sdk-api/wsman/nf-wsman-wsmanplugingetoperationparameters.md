# WSManPluginGetOperationParameters function

## Description

Gets operational information for items such as time-outs and data restrictions that are associated with the operation. A plug-in should not use these parameters for anything other than informational purposes.

## Parameters

### `requestDetails` [in]

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags` [in]

Specifies the options that are available for retrieval. This parameter must be set to either one of the following values or to a value defined by the plug-in.

#### WSMAN_PLUGIN_PARAMS_MAX_ENVELOPE_SIZE (1)

Specifies the maximum size of the operation response packet. The size includes the size of the data along with the Simple Object Access Protocol (SOAP) overhead.

**Note** Some operations have a single call into the plug-in that can cause multiple roundtrips to occur. If no requests are waiting for data when this method is called, the maximum envelope size for the previous packet is given.

#### WSMAN_PLUGIN_PARAMS_TIMEOUT (2)

Specifies the time-out of the current operation.

**Note** Some operations have a single call into the plug-in that can cause multiple roundtrips to occur. If no requests are waiting for data when this method is called, the time-out for the previous packet is given.

#### WSMAN_PLUGIN_PARAMS_REMAINING_RESULT_SIZE (3)

Specifies how much space is left for data for the current operation. The size is based on the type of operation. For example, this flag would represent how large the single result item can be for a get operation. For enumerations, the size will decrease after each object is added. After the current packet has been filled with enumerations and get operations, it will be returned to the client even though more data is being accepted and cached.

**Note** Some operations have a single call into the plug-in that can cause multiple roundtrips to occur. If no requests are waiting for data when this method is called, the remaining size is given for a cached item.

#### WSMAN_PLUGIN_PARAMS_LARGEST_RESULT_SIZE (4)

Specifies the maximum size of the data for the current operation.

#### WSMAN_PLUGIN_PARAMS_GET_REQUESTED_LOCALE (5)

Specifies the language locale that was requested by the client for the operation.

#### WSMAN_PLUGIN_PARAMS_GET_REQUESTED_DATA_LOCALE (6)

Specifies the language locale of the data that was requested by the client.

### `data` [out]

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that specifies the result object.

## Return value

The method returns **NO_ERROR** if it succeeded; otherwise, it returns an error code. The following are the most common error codes: