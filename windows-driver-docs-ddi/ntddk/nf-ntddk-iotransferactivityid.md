# IoTransferActivityId function

## Description

The IoTransferActivityId routine logs an ETW transfer event using the I/O tracing provider on behalf of the caller. This allows a driver to associate two related activity IDs without requiring a specific provider to be enabled.

## Parameters

### `ActivityId` [in]

The source activity ID.

### `RelatedActivityId` [in]

The new activity ID to be transferred from the source activity ID.