# DSM_Entry function

The **DSM_Entry** function provides the only entry point into the Data Source Manager.

## Parameters

### pOrigin

Identifies the source module of the message.\
\
This could identify an Application, a Source, or the Source Manager.

### pDest

Identifies the destination module for the message.\
\
This could identify an application or a data source. If this is NULL, the message goes to the Source Manager.

### DG

The Data Group\
\
Example: DG_IMAGE

### DAT

The Data Attribute Type\
\
Example: DAT_IMAGEMEMXFER

### MSG

The message\
\
Messages are interpreted by the destination module with respect to the Data Group and the Data Attribute Type.\
\
Example: MSG_GET

### pData

A pointer to the data structure or variable identified by the Data Attribute Type.\
\
Example: (TW_MEMREF)&ImageMemXfer where ImageMemXfer is a TW_IMAGEMEMXFER structure.

## Returns

ReturnCode\
\
Example: TWRC_SUCCESS