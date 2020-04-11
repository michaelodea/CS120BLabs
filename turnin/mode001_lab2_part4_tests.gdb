# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


test "PINA: 0x00, PINB: 0x00, PINC: 0x00 => PORTD: 0x00"
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 5
expectPORTD 0x00
checkResult

test "PINA: 0x02, PINB: 0x02, PINC: 0x02 => PORTD: 0x04"
setPINA 0x02
setPINB 0x02
setPINC 0x02
continue 5
expectPORTD 0x04
checkResult

test "PINA: 0x40, PINB: 0x25, PINC: 0x10 => PORTD: 0x74"
setPINA 0x40
setPINB 0x25
setPINC 0x10
continue 5
expectPORTD 0x74
checkResult

test "PINA: 0x20, PINB: 0x25, PINC: 0x25 => PORTD: 0x68"
setPINA 0x20
setPINB 0x25
setPINC 0x25
continue 5
expectPORTD 0x68
checkResult

test "PINA: 0x00, PINB: 0x45, PINC: 0x22 => PORTD: 0x64"
setPINA 0x00
setPINB 0x45
setPINC 0x22
continue 5
expectPORTD 0x64
checkResult























                                                                                                    
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
