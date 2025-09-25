# IX509Enrollment::get_NameValuePairs

## Description

The **NameValuePairs** property retrieves a collection of name-value pairs associated with the enrollment object.

This property is read-only.

## Parameters

## Remarks

name-value pairs are passed to the certification authority (CA) with the request for the CA to act upon. The [IX509NameValuePairs](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepairs) object is associated with the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object when the object is initialized. Therefore, before calling this property, you must initialize the **IX509Enrollment** object by calling one of the following methods.

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initialize)
* [InitializeFromRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromrequest)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromtemplatename)

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)