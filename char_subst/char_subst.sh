strip_leading_zero()
{
  val=${1#\0}
  return $val
}

strip_leading_abc()
{
  echo ${1#abc}
}

echo `strip_leading_zero 5`
echo `strip_leading_zero 05`
echo `strip_leading_zero 005`
echo `strip_leading_zero 0005`
echo `strip_leading_zero 00050`
echo `strip_leading_zero 000500`
echo `strip_leading_zero 0005000`

strip_leading_abc abcdefg
