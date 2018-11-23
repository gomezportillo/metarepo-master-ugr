# Respuestas a los tests del Tema 3 de DSS

**For each one of the (empty) elements that make up the following BPEL process template, write down its practical interpretation/use**
```html
<process>
<bpel: process name= “MyProcessOne” targetnamespace= “http://www.xmltc.cm/tls/ThisSpace” …>
<partnerLinks> (EMPTY) </partnerLinks>
<variables> (EMPTY) </variables>
<sequence> (EMPTY) </sequence>
</process>
```
```
Partner link: The 'client' role representing the requester of this service.

Variables: List of messages and XML documents used within the BPEL process.

Sequence: Set of activities coordinating the flow of messages across the services integrated within this business process
```

**Select the only one correct  of the following alternatives regarding WS-BPEL:**

- [x] It extends the interaction modelling between WS and then adds support for business transactions to the WS description language  (WSDL)

**On “PartnerLinks” and “PartnerLinkTypes”, select which one of the following sentences is not true**

- [x] Each role can specify only one _PortType_ in the WSDL file

**Regarding the “reply” activity, select which one of the following assertions is false:**

- [x] The code necessary for programming _reply_ activities or _invoke_ partners in a BPEL process is equivalent, because in both cases we execute the same operations in a single process definition

**On WS-BPEL definition, select the incorrect alternative:**

- [x] A BPEL process is a partially specified process that is not intended to be executed

**Regarding the “assign” syntactical element of BPEL 2.0, select the wrong alternative of the following ones:**

- [x] _Assign_ cannot copy a variable contents into more than one different variable at once

**Assuming that we have already done the WSDL definition file of the service, which one is a redundant step in order to define afterwards the BPEL 2.0 process**

- [x] To create the _PortTypes_ to be opened when a service request is received in the service

**With respect to  “variables” definitions in BPEL processes, which one of the following sentences is correct:**

- [x] Some BPEL orchestration engines do not accept variable initialization on-line

**Which one of the following programming facilities is not correct in the current release of BPEL programming language:**

- [x] Work flows defined with BPEL do not enable executing process elements in parallel

**One of the following items cannot be considered an objective of the BPEL notation:**

- [x] To create its own standard for orchestrating (composing) WS in a modular way

**Select which one of the following elements cannot be considered a design goal associated with WS-BPEL:**

- [x] To define a graphical representation of business processes and a particular design methodology for these processes

**With respect to the “PartnerLink” construct, which one of the following alternatives is not true:**

- [x] The partner services cannot be self invoked by the service process in which are included

**Among the following assertions about WS description with WSDL, select the incorrect one:**

- [x] The _binding_ part of a WSDL service’s description is needed to establish physical connections of that service with other services

**Regarding the difference between “receive” and “invoke” activities in BPEL 2.0, select the correct alternative:**

- [x] The PartnerLinks of the _invoke_ activity (for which to specify an operation) and of the _receive_ activity (from which to receive information) used when a service's operation is called are the same
