Retesting of software is done frequently during the software development life cycle and
in particular in regression testing. In regression testing software grows and evolves that
create new test cases and added them to a test suite to exercise the latest changes in
the software[5]. Due to many versions of the development of the projects, the possibility
of redundant test cases in test suite is more .The redundant test case may in respect to
the testing requirements for which they were generated. Due to limitation of time and
resource for retesting the software every time before a new version is released, it is really
important to search for techniques that ensure manageable test suites size by removing
redundant test cases without hampering the performance of the software. This process is
popularly called test suite minimization.

The motivation behind this topic is that the time taken and cost involved in testing phase
of software development life cycle increases rapidly as the test suite size increases.So to
obtain the correct results i.e. minimized test suite that will reduce the cost and effort
involved in testing.

We have used incremental model of software development life cycle as after the Require-
ment Gathering and Analysis we have built different modules and each module is being tested before we built the next module to reach at the final results.

As the software is modified and new test cases are added to the test- suite, the size of the
test-suite grows and the cost of regression testing increases.This paper investigates the use
of an evolutionary approach, called genetic algorithms, for test-suite reduction[2]. The
algorithm builds the initial population based on test history, calculates the fitness value
using coverage and cost information, and then selectively breeds the successive generations

using genetic operations. This generational process is repeated until a minimized test-
suite is found[4].

Test-suite reduction techniques have been extensively studied. Harrold, Gupta, and
Soffa proposed a methodology for controlling the size of a test suite. Jones and Harrold
presented an algorithm for test-suite reduction that can be tailored effectively for use with
Modified Condition/Decision Coverage (MC/DC)[1].
In order to perform test-suite reduction, we should do something includes:

• Maintaining a testing pool where contains all the test cases used in previous test
activities.
• Keeping the test coverage information which denotes how many and which parts of
the program tested by each test cases during the previous tests.
• Recording the test-execution cost information that measures the amount of resources
each test-cases execution needs.
