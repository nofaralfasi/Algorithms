public class Solution {
        public boolean isValid(String s) {
            Stack<Character> stack = new Stack<>();
            Map<Character, Character> map = new HashMap<>();
            map.put('(', ')');
            map.put('[', ']');
            map.put('{', '}');
            for(char c : s.toCharArray()) {
                if(map.containsKey(c)) {
                    stack.push(c);
                } else {
                    if(!stack.isEmpty() && map.get(stack.peek()) == c) {
                        stack.pop();
                    } else {
                        return false;
                    }
                }
            }
            return stack.isEmpty();
        }
}
