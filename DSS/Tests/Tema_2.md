# Respuestas a los tests del Tema 2 de DSS

**Select which one of the following elements cannot be considered as an SOA own characteristic**

- [x] To use one SOA for software development propitiates loosely coupling among services.

**On WS-BPEL definition, select the incorrect alternative**

- [x]  BPEL process is a partially specified process that is not intended to be executed.

**Select the only correct alternative about Web Service composition strategies**

- [x] With WS orchestration the business process logics is actually centralized but a service's capability of composition with other services and components is always preserved.

**Select the incorrect alternative about the differences between architectural styles and architectural patterns**

- [x] Architectural styles need the definition of a problem's context.

**About the concept of “event”, select which one is not true**

- [x] What is transmitted between two cooperative Web services.

**Which one of the following alternatives cannot be considered an advantage of Grid Computing (GC)**

- [x] GC programming always produces interoperability of applications for heterogeneous platforms.

**Select the only correct answer to the following question on the correct "design pattern" concept that is used in the software development activity**

- [x] A design pattern proposes a general solution to a problem-type that appears in a given content for any execution platform.

**Which one of the following alternatives characterises more precisely the concept of "software architectural style"**

- [x] A set of features that make the software architecture uniquely identifiable.

**Select the correct answer among the following ones the quality characteristics that propitiates the Interceptor pattern**

- [x] Chains of interceptors can yield performance problems and or lead to application locking up.

**Select only the correct one of the following alternatives regarding the differences between "architectural styles" and "architectural patterns"**

- [x] An architectural style only describes the structural and general skeleton of software applications.

**About EDA (Event Driven Architectures), select which one is true:**

- [x] EDA complements SOA, since events can be initiated, transmitted, managed, etc. by SOAP messages.

**About Grid Computing (GC) , select which one is not true:**

- [x] With CG we always guarantee quality of service (QoS).

**Write down the "Cliente.java" of the first practical assignment that used the Interceptor pattern with the given class GestorFiltros.java as it follows:**

```Java
 public GestorFiltros( Interfaz objetivo )
{
    this.cadena_filtros= new CadenaFiltros();
    this.cadena_filtros.setObjetivo( t );
}

public void setFiltro( Filtro filtro )
{
    this.cadena_filtros.addFiltro( filtro );
}

public void ejecutar( double peticion ) throws IOException, URIException
{
    this.cadena_filtros.ejecutar( peticion );
}
```

 **Select the only correct answer to the following question about the differences that exist between frameworks and design patterns**

- [x] One framework is an application skeleton that must be adapted to the concrete requirements of a software applications by the programmer.

**Select the incorrect answer regarding architectural patterns and software quality forestalling**

- [x] We can anticipate the quality of software application with respect to the possible fulfillment of ISO quality characteristics.
