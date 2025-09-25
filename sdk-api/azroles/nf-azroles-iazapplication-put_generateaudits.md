# IAzApplication::put_GenerateAudits

## Description

The **GenerateAudits** property sets or retrieves a value that indicates whether run-time audits should be generated.

This property is read/write.

## Parameters

## Remarks

The **GenerateAudits** property controls client context creation, client context deletion, and access check run-time auditing. The client context can be created by a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID), name, or token.

The [AzAuthorizationStore.GenerateAudits](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_generateaudits) property controls application initialization auditing.